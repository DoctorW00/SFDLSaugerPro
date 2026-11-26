#import <Cocoa/Cocoa.h>

// Eigene View: zeichnet das App-Icon und den Fortschrittsbalken selbst.
// Ein NSProgressIndicator in einer NSDockTile aktualisiert sich nicht zuverlaessig,
// weil die View in keinem Fenster haengt.
@interface SFDLDockProgressView : NSView
@property (nonatomic, assign) double progress;   // 0..100
@property (nonatomic, retain) NSImage *iconImage;
@end

@implementation SFDLDockProgressView

- (void)dealloc
{
    [_iconImage release];
    [super dealloc];
}

- (void)drawRect:(NSRect)dirtyRect
{
    (void)dirtyRect;
    NSRect b = [self bounds];

    // App-Icon (Bundle-Icon) als Hintergrund
    if (self.iconImage) {
        [self.iconImage drawInRect:b
                          fromRect:NSZeroRect
                         operation:NSCompositingOperationSourceOver
                          fraction:1.0];
    }

    // Balken-Geometrie
    CGFloat margin = b.size.width * 0.08;
    CGFloat height = b.size.height * 0.11;
    NSRect track = NSMakeRect(margin,
                              b.size.height * 0.06,
                              b.size.width - 2 * margin,
                              height);
    CGFloat radius = height / 2.0;

    // Hintergrund des Balkens
    [[NSColor colorWithCalibratedWhite:0.16 alpha:0.88] setFill];
    [[NSBezierPath bezierPathWithRoundedRect:track xRadius:radius yRadius:radius] fill];

    // Fortschritt
    double p = self.progress;
    if (p < 0) p = 0;
    if (p > 100) p = 100;
    if (p > 0) {
        NSRect fill = track;
        fill.size.width = MAX(height, track.size.width * (CGFloat)(p / 100.0));

        [NSGraphicsContext saveGraphicsState];
        [[NSBezierPath bezierPathWithRoundedRect:track xRadius:radius yRadius:radius] addClip];
        [[NSColor colorWithCalibratedRed:76.0/255.0 green:175.0/255.0 blue:80.0/255.0 alpha:1.0] setFill];
        [[NSBezierPath bezierPathWithRoundedRect:fill xRadius:radius yRadius:radius] fill];
        [NSGraphicsContext restoreGraphicsState];
    }
}

@end

static SFDLDockProgressView *s_view = nil;
static NSImage *s_baseIcon = nil;

static void runOnMain(void (^block)(void))
{
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

void macSetDockProgress(int percentage)
{
    runOnMain(^{
        NSDockTile *tile = [NSApp dockTile];

        // Bundle-Icon einmalig sichern, bevor die Kachel ersetzt wird
        if (!s_baseIcon) {
            s_baseIcon = [[NSApp applicationIconImage] copy];
        }

        if (!s_view) {
            NSSize sz = [tile size];
            s_view = [[SFDLDockProgressView alloc] initWithFrame:NSMakeRect(0, 0, sz.width, sz.height)];
            s_view.iconImage = s_baseIcon;
        }

        s_view.progress = percentage;

        if ([tile contentView] != s_view) {
            [tile setContentView:s_view];
        }
        [s_view setNeedsDisplay:YES];
        [tile display];
    });
}

void macClearDockProgress()
{
    runOnMain(^{
        NSDockTile *tile = [NSApp dockTile];
        [tile setContentView:nil];   // zurueck zum normalen App-Icon
        [tile display];
    });
}
