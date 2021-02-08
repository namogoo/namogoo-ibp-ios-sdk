//
//  CategoryCell.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 18/10/2020.
//

import UIKit

class CategoryCell: UITableViewCell {
    struct ViewModel {
        let title: String
    }
    
    @IBOutlet weak var label: UILabel!
    
    static let identifier = "CategoryCell"
    var viewModel: ViewModel? {
        didSet {
            label.text = viewModel?.title
        }
    }
    
}
