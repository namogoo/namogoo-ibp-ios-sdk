//
//  CartCell.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 18/10/2020.
//

import UIKit

class CartCell: UITableViewCell {
    struct ViewModel {
        let image: String
        let product: String
        let cost: String
        let amount: String
    }
    
    @IBOutlet weak var productImage: UIImageView!
    @IBOutlet weak var amount: UILabel!
    @IBOutlet weak var name: UILabel!
    @IBOutlet weak var cost: UILabel!
    
    static let identifier = "CartCell"
    var viewModel: ViewModel? {
        didSet {
            if let imageUrl = viewModel?.image, let url = NSURL(string: imageUrl) {
                productImage.loadImage(from: url)
            }
            
            amount.text = viewModel?.amount
            name.text = viewModel?.product
            cost.text = viewModel?.cost
        }
    }
}
