//
//  AppDelegate.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 14/10/2020.
//

import UIKit
import NamogooIBPSDK

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    
    enum PopupType {
        case appBased, sdkBased, both
    }
    
    static let popupType: PopupType = .sdkBased

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        NamogooIBP.shared.start(id: "MOQFHM369", sessionId: "123ios12", cartDelegate: DataManager.shared, referrer: nil, options: launchOptions)
        NamogooIBP.shared.automaticDisplayPermissions = AppDelegate.popupType == PopupType.sdkBased || AppDelegate.popupType == PopupType.both ? .allow : .block
        
        DataManager.shared.setup()
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    @available(iOS 13.0, *)
    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    @available(iOS 13.0, *)
    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

