//
//  ProductModel.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 19/10/2020.
//

import Foundation

struct ProductModel: Codable {
    let id: Int
    let title: String
    let price: Double
    let description: String
    let category: String
    let image: String
}
