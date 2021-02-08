//
//  PopupController.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 19/11/2020.
//

import UIKit

class PopupController: UIViewController, Instantiable {
    static var storyboardName: StringConvertible {
        return StoryboardName.main
    }
    
    struct ViewModel {
        let text: String
        let coupon: String
        let expiration: Date
    }
    
    @IBOutlet weak var container: UIView!
    @IBOutlet weak var byUsingLabel: UILabel!
    @IBOutlet weak var offerExpiresLabel: UILabel!
    @IBOutlet weak var expirationLabel: UILabel!
    @IBOutlet weak var topText: UILabel!
    @IBOutlet weak var couponLabel: UILabel!
    @IBOutlet weak var copyButton: UIButton!
    @IBOutlet weak var closeButton: UIButton!
    @IBOutlet weak var smallTextLabel: UILabel!
    @IBOutlet weak var poweredByLabel: UILabel!
    
    var timer: Timer?
    
    var viewModel: ViewModel? {
        didSet {
            guard let viewModel = viewModel else { return }
            topText.text = viewModel.text
            couponLabel.text = viewModel.coupon
        }
    }
    
    @IBAction func closeTapped(_ sender: Any) {
        self.dismiss(animated: true, completion: nil)
    }
    
    @IBAction func copyTapped(_ sender: Any) {
        UIPasteboard.general.string = couponLabel.text
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        timer = Timer.scheduledTimer(withTimeInterval: 10, repeats: true) { timer in
            self.setExpirationTime()
        }

    }
    
    func setExpirationTime() {
        guard let viewModel = self.viewModel else {
            return
        }
        
        let diffComponents = Calendar.current.dateComponents([.day, .hour, .minute], from: Date(), to: viewModel.expiration)
        let minutes = diffComponents.minute ?? 0
        let hours = diffComponents.hour ?? 0
        let days = diffComponents.day ?? 0
        
        DispatchQueue.main.async {
            self.expirationLabel.text = "\(days) Days, \(hours) Hours, \(minutes) Minutes"
        }
    }
}
