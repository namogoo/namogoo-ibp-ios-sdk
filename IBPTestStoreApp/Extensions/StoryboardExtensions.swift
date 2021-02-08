//
//  StoryboardExtensions.swift
//  NamogooBrowserExtension
//
//  Created by Kali Spassov on 12/08/2020.
//  Copyright © 2020 Namogoo. All rights reserved.
//

import UIKit

protocol StringConvertible {
    var rawValue: String {get}
}

protocol Instantiable: class {
    static var storyboardName: StringConvertible {get}
}

extension Instantiable {
    static func instantiateFromStoryboard() -> Self {
        return instantiateFromStoryboardHelper()
    }

    private static func instantiateFromStoryboardHelper<T>() -> T {
        let identifier = String(describing: self)
        let storyboard = UIStoryboard(name: storyboardName.rawValue, bundle: nil)
        return storyboard.instantiateViewController(withIdentifier: identifier) as! T
    }
}

//MARK: -
extension String: StringConvertible { // allow string as storyboard name
    var rawValue: String {
        return self
    }
}

enum StoryboardName: String, StringConvertible {
    case main = "Main"
}
