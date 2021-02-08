//
//  TabBatController.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 25/10/2020.
//

import UIKit

class TabBarController: UITabBarController {
    
    
}

extension TabBarController: UITabBarControllerDelegate {
    
    override func tabBar(_ tabBar: UITabBar, didSelect item: UITabBarItem) {
        if let nav = self.viewControllers?[1] as? UINavigationController {
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.1, execute: {
                nav.popToRootViewController(animated: true)
            })
        }
    }
}
