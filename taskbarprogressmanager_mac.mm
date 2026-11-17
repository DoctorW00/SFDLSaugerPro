#import <Cocoa/Cocoa.h>

static NSProgressIndicator *s_indicator = nil;
static NSImageView *s_view = nil;

void macSetDockProgress(int percentage)
{
    NSDockTile *tile = [NSApp dockTile];

    if (!s_view) {
        NSSize sz = [tile size];
        s_view = [[NSImageView alloc] initWithFrame:NSMakeRect(0, 0, sz.width, sz.height)];
        [s_view setImage:[NSApp applicationIconImage]];

        s_indicator = [[NSProgressIndicator alloc]
            initWithFrame:NSMakeRect(8, 6, sz.width - 16, 14)];
        [s_indicator setStyle:NSProgressIndicatorStyleBar];
        [s_indicator setIndeterminate:NO];
        [s_indicator setMinValue:0];
        [s_indicator setMaxValue:100];
        [s_indicator setAutoresizingMask:NSViewWidthSizable];
        [s_view addSubview:s_indicator];
    }

    [s_indicator setDoubleValue:percentage];
    [s_indicator setHidden:NO];
    [tile setContentView:s_view];
    [tile display];
}

void macClearDockProgress()
{
    NSDockTile *tile = [NSApp dockTile];
    [tile setContentView:nil];
    [tile display];
}