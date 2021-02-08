//
//  PurchaseCompleteController.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 14/10/2020.
//

import UIKit

class PurchaseCompleteController: UIViewController, Instantiable {
    static var storyboardName: StringConvertible {
        return StoryboardName.main
    }
    
    // MARK: - Outlets
    @IBOutlet weak var stackContainer: UIStackView!
    
    @IBAction func doneTapped(_ sender: Any) {
        self.navigationController?.popViewController(animated: true)
    }
    
    
    // MARK: - Life cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        DispatchQueue.main.asyncAfter(deadline: .now() + 3.0, execute: { [weak self] in
            self?.navigationController?.popViewController(animated: true)
        })
        
    }
    
    // MARK: - Convenience
    
    
}
