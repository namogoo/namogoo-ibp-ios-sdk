//
//  CPUStats.h
//  NamogooIBPSDK
//
//  Created by Amir Zucker on 06/07/2020.
//  Copyright © 2020 Amir Zucker. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CPUStats : NSObject
+(NSString *)getCurrentAppCpuUsage;
+(NSString *)getTotalCpuUsage;

+(int)getNumberOfCores;

@end

NS_ASSUME_NONNULL_END
