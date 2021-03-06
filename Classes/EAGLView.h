//
//  EAGLView.h
//  ParticleEmitter
//
//  Created by EBattal on 8/9/10.

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "ESRenderer.h"

// This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView subclass.
// The view content is basically an EAGL surface you render your OpenGL scene into.
// Note that setting the view non-opaque will only work if the EAGL surface has an alpha channel.
@interface EAGLView : UIView
{    
@private
    id <ESRenderer> renderer;

    BOOL animating;
    BOOL displayLinkSupported;
    NSInteger animationFrameInterval;
    // Use of the CADisplayLink class is the preferred method for controlling your animation timing.
    // CADisplayLink will link to the main display and fire every vsync when added to a given run-loop.
    // The NSTimer class is used only as fallback when running on a pre 3.1 device where CADisplayLink
    // isn't available.
    id displayLink;
    NSTimer *animationTimer;
	
	//GUI
	UIButton *addNew, *skip, *stopOne, *stopAll;
}

@property (readonly, nonatomic, getter=isAnimating) BOOL animating;
@property (nonatomic) NSInteger animationFrameInterval;
@property (nonatomic,retain) IBOutlet UIButton *addNew, *skip, *stopOne, *stopAll;

- (void)startAnimation;
- (void)stopAnimation;
- (void)drawView:(id)sender;
- (IBAction) actionAddNew;
- (IBAction) actionSkip;
- (IBAction) actionStopOne;
- (IBAction) actionStopAll;
@end
