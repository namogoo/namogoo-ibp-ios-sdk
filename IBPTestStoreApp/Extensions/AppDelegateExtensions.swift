//
//  AppDelegateExtensions.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 21/10/2020.
//

import UIKit

extension UIApplication {
    func getTabController() -> UITabBarController? {
        var rootVC: UITabBarController? = nil
        if #available(iOS 13.0, *) {
            for scene in UIApplication.shared.connectedScenes {
                if scene.activationState == .foregroundActive {
                    if let rootTabController = ((scene as? UIWindowScene)?.delegate as? UIWindowSceneDelegate)?.window??.rootViewController as? UITabBarController {
                        rootVC = rootTabController
                        break
                    }
                }
            }
        } else {
            if let appD = UIApplication.shared.delegate as? AppDelegate,
               let tabBarController = appD.window?.rootViewController as? UITabBarController {
                rootVC = tabBarController
            }
        }
        return rootVC
    }
}
