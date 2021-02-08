//
//  ProductCell.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 18/10/2020.
//

import UIKit

class ProductCell: UICollectionViewCell {
    struct ViewModel {
        let image: String
        let title: String
        let subTitle: String
    }
    
    @IBOutlet weak var image: UIImageView!
    @IBOutlet weak var title: UILabel!
    @IBOutlet weak var subtitle: UILabel!
    
    static let reuseIdentifier = "ProductCell"
    var viewModel: ViewModel? {
        didSet {
            if let imageUrl = viewModel?.image, let url = NSURL(string: imageUrl) {
                image.loadImage(from: url)
            }
            
            title.text = viewModel?.title
            subtitle.text = viewModel?.subTitle
        }
    }
    
}
