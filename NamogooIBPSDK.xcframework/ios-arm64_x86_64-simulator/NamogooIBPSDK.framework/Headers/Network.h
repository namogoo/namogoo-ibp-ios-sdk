//
//  Network.h
//  NamogooIBPSDK
//
//  Created by Amir Zucker on 09/07/2020.
//  Copyright © 2020 Amir Zucker. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Network : NSObject
+(BOOL) isWiFiEnabled;
+(NSDictionary *)wifiDetails;
+(BOOL) isWiFiConnected;
//+(NSString *) BSSID;
//+(NSString *) SSID;
//+(NSString *) getInternalIPAddress;
+(BOOL) isConnectedToVPN;

@end

NS_ASSUME_NONNULL_END
