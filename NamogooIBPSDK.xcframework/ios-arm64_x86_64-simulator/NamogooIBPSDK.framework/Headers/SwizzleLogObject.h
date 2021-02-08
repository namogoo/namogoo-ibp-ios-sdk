//
//  SwizzleLogObject.h
//  NamogooIBPSDK
//
//  Created by Amir Zucker on 15/07/2020.
//  Copyright © 2020 Amir Zucker. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SwizzleLogObject : NSObject
@property (strong, nonatomic) NSString *action;
@property (strong, nonatomic) NSDictionary *value;

-(instancetype)initWith:(NSString *)action andValue: (NSDictionary *)value;

@end

NS_ASSUME_NONNULL_END
