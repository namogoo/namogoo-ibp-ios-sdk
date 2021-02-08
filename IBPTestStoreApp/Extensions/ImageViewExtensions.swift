//
//  ImageViewExtensions.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 20/10/2020.
//

import UIKit

extension UIImageView {
    func loadImage(from nsurl: NSURL?) {
        guard let nsurl = nsurl, let url = nsurl.absoluteURL else {
            return
        }
        
        URLSession.shared.dataTask(with: url,
                                   completionHandler: { data, response, error in
                                    
                                    guard let data = data, error == nil else { return }
                                    
                                    DispatchQueue.main.async() { [weak self] in
                                        guard let self = self, let image = UIImage(data: data) else {
                                            return
                                        }
                                        
                                        self.image = image
                                    }
                                   }).resume()
    }
}
