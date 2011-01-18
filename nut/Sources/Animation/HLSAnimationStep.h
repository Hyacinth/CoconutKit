//
//  HLSAnimationStep.h
//  nut
//
//  Created by Samuel Défago on 8/10/10.
//  Copyright 2010 Hortis. All rights reserved.
//

#define ANIMATION_STEP_ALPHA_NOT_SET                               -1.f

/**
 * An animation is made of animation steps, moving a view within its superview from a position into another one (and maybe animating 
 * other animatable properties as well during this process). An animation object simply applies animation steps onto the view
 * it animates. Each step is applied to the state of the animation as yielded by the previous animation step.
 *
 * Several convenience constructors are available to help you create animation steps without requiring you to calculate coordinates
 * explicitly (you can if you require this flexibility, of course). After you have created a step object, you can use the other accessors
 * to set other animatable properties or animation settings.
 *
 * Remark: This class was initially named HLSAnimationFrame, but was renamed to avoid confusion with the UIView frame property
 *         (which is the view property an animation step usually alters!)
 *
 * Designated initializer: init (create an animation step with default settings)
 * Copy behavior: deep copy
 */
@interface HLSAnimationStep : NSObject <NSCopying> {
@private
    CGAffineTransform m_transform;
    CGFloat m_alpha;
    NSTimeInterval m_duration;
    NSTimeInterval m_delay;
    UIViewAnimationCurve m_curve;
    NSString *m_tag;
}

/**
 * Convenience constructor for an animation step with default settings
 */
+ (HLSAnimationStep *)animationStep;

/**
 * Convenience constructor for creating an identity animation step for a view (no change, duration is 0). Such animations are
 * usually used as first animation step
 */
+ (HLSAnimationStep *)animationStepIdentityForView:(UIView *)view;

/**
 * Animation step moving a view between two frames. Both frames must describe positions of the view to animate
 * relative to its superview (otherwise the result is undefined)
 */
+ (HLSAnimationStep *)animationStepAnimatingViewFromFrame:(CGRect)fromFrame toFrame:(CGRect)toFrame;

/**
 * Animation step applying a translation to a view frame
 */
+ (HLSAnimationStep *)animationStepTranslatingViewWithDeltaX:(CGFloat)deltaX
                                                      deltaY:(CGFloat)deltaY;

/**
 * The affine transformation which must be applied during the step
 * Default value is the identity
 */
@property (nonatomic, assign) CGAffineTransform transform;

/**
 * The opacity at the end of the animation step (valid values lie between 0.f and 1.f). If not set (special value
 * ANIMATION_STEP_ALPHA_NOT_SET), the alpha is not altered by the animation
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 * Animation step settings
 */
@property (nonatomic, assign) NSTimeInterval duration;                      // default: 0.2
@property (nonatomic, assign) NSTimeInterval delay;                         // default: 0.f
@property (nonatomic, assign) UIViewAnimationCurve curve;                   // default: UIViewAnimationCurveEaseInOut

/**
 * Optional tag to help identifying animation steps
 */
@property (nonatomic, retain) NSString *tag;

@end
