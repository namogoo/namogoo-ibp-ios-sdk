//
//  APIManager.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 19/10/2020.
//

import UIKit

class APIManager {
    private struct URLs {
        static let products = "https://fakestoreapi.com/products"
        static let pictures = "https://picsum.photos/400/100"
    }
    
    // MARK : - Static REST functions
    func getProducts(limit: Int = 20, cb: @escaping ([ProductModel])->Void) {
        guard let url = URL(string: URLs.products + "?limit=\(limit)") else {
            cb([])
            return
        }
        AF.request(url.absoluteString).response { response in
            switch response.result {
            case .success(let data):
                do {
                    if let data = data {
                        let products = try JSONDecoder().decode([ProductModel].self, from: data)
                        cb(products)
                    }
                } catch {
                    cb([])
                }
            case .failure( _):
                cb([])
            }
        }
    }
    
    func getCategories(cb: @escaping ([CategoryModel])->Void) {
        guard let url = URL(string: URLs.products) else {
            cb([])
            return
        }
        AF.request(url.absoluteString).response { response in
            switch response.result {
            case .success(let data):
                do {
                    if let data = data {
                        let products = try JSONDecoder().decode([ProductModel].self, from: data)
                        let categories = products.unique{$0.category}
                        if categories.count > 0 {
                            var images: [UIImage] = []
                            for _ in categories {
                                self.getImage(cb: { image in
                                    guard let image = image else {
                                        return
                                    }
                                    images.append(image)
                                    if images.count == categories.count {
                                        var output: [CategoryModel] = []
                                        for (index, item) in categories.enumerated() {
                                            output.append(CategoryModel(bannerImage: images[index], name: item.category) )
                                        }
                                        cb(output)
                                    }
                                })
                            }
                        } else {
                            cb([])
                        }
                        
                    }
                } catch {
                    cb([])
                }
            case .failure( _):
                cb([])
            }
        }
    }
    
    func getImage(cb: @escaping (UIImage?)->Void) {
        guard let url = URL(string: URLs.pictures) else {
            cb(nil)
            return
        }
        AF.request(url.absoluteString).response { response in
            switch response.result {
            case .success(let data):
                    if let data = data, let image = UIImage(data: data) {
                        cb(image)
                    }
            case .failure( _):
                cb(nil)
            }
        }
    }
}

