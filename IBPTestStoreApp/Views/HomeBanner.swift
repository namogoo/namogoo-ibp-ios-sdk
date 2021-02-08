//
//  HomeBanner.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 18/10/2020.
//

import UIKit

class HomeBanner: UICollectionViewCell {
    
    struct ViewModel {
        let image: UIImage
        let text: String
    }
    
    @IBOutlet weak var image: UIImageView!
    @IBOutlet weak var text: UILabel!
    
    
    static let reuseIdentifier = "HomeBanner"
    
    var viewModel: ViewModel? {
        didSet {
            image.image = viewModel?.image
            text.text = viewModel?.text
        }
    }
    
    override func awakeFromNib() {
        
        // Added for fix an issue with layout in iOS 12.
            super.awakeFromNib()

            contentView.translatesAutoresizingMaskIntoConstraints = false

            let leftConstraint = contentView.leftAnchor.constraint(equalTo: leftAnchor)
            let rightConstraint = contentView.rightAnchor.constraint(equalTo: rightAnchor)
            let topConstraint = contentView.topAnchor.constraint(equalTo: topAnchor)
            let bottomConstraint = contentView.bottomAnchor.constraint(equalTo: bottomAnchor)
            NSLayoutConstraint.activate([leftConstraint, rightConstraint, topConstraint, bottomConstraint])
        }
    
}
