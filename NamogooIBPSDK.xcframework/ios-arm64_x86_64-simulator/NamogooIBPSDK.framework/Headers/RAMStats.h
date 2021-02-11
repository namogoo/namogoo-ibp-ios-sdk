//
//  RAMStats.h
//  NamogooIBPSDK
//
//  Created by Amir Zucker on 06/07/2020.
//  Copyright © 2020 Amir Zucker. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RAMStats : NSObject
+(double)getUsedRamAmount;
+(double)getFreeRamAmount;
+(double)getTotalRamAmount;

@end

NS_ASSUME_NONNULL_END
