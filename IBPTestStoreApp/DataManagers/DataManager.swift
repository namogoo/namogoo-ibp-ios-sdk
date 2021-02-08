//
//  DataManager.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 20/10/2020.
//

import UIKit
import NamogooIBPSDK

class DataManager {
    
    struct Events {
        static let categoriesUpdated =  NSNotification.Name(rawValue: "nmgStore.categoriesUpdated")
    }

    
    // MARK: - Shared object
    static let shared = DataManager()
    
    // MARK: - Dependencies
    private let cartManager = CartManager()
    let store = ProductsStore()
    private let api = APIManager()
    
    // MARK: - Data getters
    func setup() {
        api.getCategories(cb: { categories in
            self.store.categories = categories
            NotificationCenter.default.post(name: DataManager.Events.categoriesUpdated, object: nil)
        })
        
        api.getProducts(limit: 30, cb: { products in
            self.store.products = products
        })
    }
    
    func updateCart(item id: Int, amount: Int) {
        cartManager.itemsInCart[id] = amount
        updateBadge()
    }
    
    private func updateBadge() {
        if let rootVC = UIApplication.shared.getTabController(),
           let cartTab = rootVC.tabBar.items?[2] {
            let value = cartManager.itemsInCart.reduce(0){ $0 + $1.value }
            if value > 0 {
                cartTab.badgeValue = "\(value)"
            } else {
                cartTab.badgeValue = nil
            }
        }
    }
    
    func checkCart(item id: Int) -> Int {
        if let amount = cartManager.itemsInCart[id] {
            return amount
        } else {
            return 0
        }
    }
    
    func getAllCartItems() -> [Int:Int] {
        return cartManager.itemsInCart.filter({ $0.value > 0 })
    }
    
    func setCartCurrency(to currency: String) {
        cartManager.currency = currency
    }
    
    func getCurrencySymbol() -> String {
        switch cartManager.currency.lowercased() {
        case "usd":
            return "$"
        case "eur":
            return "€"
        default:
            return "$"
        }
    }
}

extension DataManager: IBPCartDelegate {
    func getCartItems() -> [IBPCartItem] {
        return [] // TODO:implement
    }
    
    func getCartTotal() -> Double {
        return cartManager.itemsInCart.reduce(0.0){ (current, next) in current + (Double(next.value) * (store.products.first(where: { next.key == $0.id })?.price ?? 0.0)) }
    }
    
    func getCartSubtotal() -> Double {
        return cartManager.itemsInCart.reduce(0.0){ (current, next) in current + (Double(next.value) * (store.products.first(where: { next.key == $0.id })?.price ?? 0.0)) }
    }
    
    func getUserCurrency() -> IBPCurrency {
        switch cartManager.currency.lowercased() {
        case "usd":
            return .USD
        case "eur":
            return .EUR
        default:
            return .USD
        }
    }
}
