//
//  IBPSDKSwizzlingManager.h
//  NamogooIBPSDKSDK
//
//  Created by Amir Zucker on 14/07/2020.
//  Copyright © 2020 Amir Zucker. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SwizzleLogObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface IBPSDKSwizzlingManager : NSObject

+(instancetype)sharedInstance;

-(void)swizzleUIViewControllerFunctions;
-(void)swizzleUIApplicationFunctions;
-(void)swizzleUIPickerViewFunctions;
-(void)swizzleUITextFieldFunctions;
-(void)swizzleUITextViewFunctions;
-(void)swizzleUIButtonFunctions;
-(void)swizzleNSUrlFunctions;
-(void)swizzleUILabelFunctions;

-(void)setSwizzlingLogObject: (SwizzleLogObject *)logObject;
@end

NS_ASSUME_NONNULL_END
