//
//  ViewController.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 14/10/2020.
//

import UIKit
import NamogooIBPSDK

class CartController: UIViewController {
    // MARK: - Outlets
    @IBOutlet weak var checkoutButton: UIButton!
    @IBOutlet weak var couponTextField: UITextField!
    @IBOutlet weak var applyCouponButton: UIButton!
    @IBOutlet weak var couponFeedbackLabel: UILabel!
    @IBOutlet weak var cartTable: UITableView!
    @IBOutlet weak var totalCostLabel: UILabel!
    
    private let constText = "%s OFF!"
    private var discount: Double = 0.0
    private var couponsApplied: [String] = []
    
    @IBAction func checkoutTapped(_ sender: Any) {
        let items = DataManager.shared.getAllCartItems()
        if items.count > 0 {
            NamogooIBP.shared.reportOrderCompleted(IBPOrderParams(orderId: "test123", couponsUsed: couponsApplied, taxCost: 0.0, shippingCost: 0.0, payload: [:]))
            self.navigationController?.pushViewController(PurchaseCompleteController.instantiateFromStoryboard(), animated: true)
            for item in items {
                DataManager.shared.updateCart(item: item.key, amount: 0)
            }
        } else {
            let alertController = UIAlertController(title: "No items in cart", message: "Add some items to in the search tab!", preferredStyle: .alert)
            let cancelAction = UIAlertAction(title: "OK", style: UIAlertAction.Style.default) {
                UIAlertAction in
                alertController.dismiss(animated: true, completion: nil)
            }
            
            // Add the actions
            alertController.addAction(cancelAction)
            self.present(alertController, animated: true, completion: nil)
        }
    }
    
    @IBAction func applyCouponTapped(_ sender: Any) {
        NamogooIBP.shared.getIncentive(completionHandler: { incentive, error in
            guard let incentive = incentive, let userInputCoupon = self.couponTextField.text else { return }
            DispatchQueue.main.async {
                if incentive.couponCode == userInputCoupon {
                    NamogooIBP.shared.reportEvent(type: .couponAdded, payload:[:])
                    self.discount = incentive.discount
                    self.couponFeedbackLabel.text = "Coupon applied!"
                    if !self.couponsApplied.contains(userInputCoupon) {
                        self.couponsApplied.append(userInputCoupon)
                    }
                } else {
                    self.couponFeedbackLabel.text = "Coupon not recognized."
                }
                self.couponFeedbackLabel.isHidden = false
                self.couponTextField.text = nil
                self.calculateTotal()
            }
        })   
    }
    
    // MARK: - Life cycle
    override func viewDidLoad() {
        super.viewDidLoad()

        cartTable.delegate = self
        cartTable.dataSource = self

    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        cartTable.reloadData()
        calculateTotal()

        if AppDelegate.popupType == .appBased || AppDelegate.popupType == .both {
            showPopup()
        }
    }
    
    // MARK: - Convenience
    func calculateTotal() {
        totalCostLabel.text = "Total: \(DataManager.shared.getCartTotal() * (100 - discount) / 100)"
    }
    
    func showPopup() {
        NamogooIBP.shared.getIncentive(completionHandler: { incentive, status in
            guard let incentive = incentive else { return }
            DispatchQueue.main.async {
                let popup = PopupController.instantiateFromStoryboard()

                let viewModel = PopupController.ViewModel(text: self.constText.replacingOccurrences(of: "%s", with: "\(incentive.discount)%"), coupon: "\(incentive.couponCode)", expiration: Date(timeIntervalSince1970: incentive.expiration / 1000.0))

                popup.modalPresentationStyle = .overCurrentContext
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.15, execute: {
                    popup.viewModel = viewModel
                    popup.setExpirationTime()
                })

                self.navigationController?.present(popup, animated: true, completion: nil)
            }
        })
    }
}

extension CartController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return DataManager.shared.getAllCartItems().count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: CartCell.identifier, for: indexPath) as? CartCell else {
            return UITableViewCell()
        }
        
        let dataAsDict = DataManager.shared.getAllCartItems()
        
        let sorted: [(ProductModel, Int)] = dataAsDict.compactMap { (key, value) in
            if value > 0, let product = DataManager.shared.store.products.first(where: { $0.id == key}) {
                return (product, value)
            } else {
                return nil
            }
        }
            
        let data = sorted[indexPath.row]
        

        cell.viewModel = CartCell.ViewModel(image: data.0.image, product: data.0.title, cost: "\(data.0.price)\(DataManager.shared.getCurrencySymbol())", amount: "\(data.1)")
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let alertController = UIAlertController(title: "Remove Items?", message: "Are you sure you want to remove these items from your cart?", preferredStyle: .alert)
        
        // Create the actions
        let okAction = UIAlertAction(title: "Remove", style: UIAlertAction.Style.default) {
            UIAlertAction in
            let dataAsDict = DataManager.shared.getAllCartItems()
            
            let sorted: [(ProductModel, Int)] = dataAsDict.compactMap { (key, value) in
                if let product = DataManager.shared.store.products.first(where: { $0.id == key}) {
                    return (product, value)
                } else {
                    return nil
                }
            }
                
            let data = sorted[indexPath.row]
            DataManager.shared.updateCart(item: data.0.id, amount: 0)
            DispatchQueue.main.async {
                self.cartTable.reloadData()
                self.calculateTotal()
            }
        }
        
        let cancelAction = UIAlertAction(title: "Cancel", style: UIAlertAction.Style.cancel) {
            UIAlertAction in
            alertController.dismiss(animated: true, completion: nil)
        }
        
        // Add the actions
        alertController.addAction(okAction)
        alertController.addAction(cancelAction)
        
        // Present the controller
        self.present(alertController, animated: true, completion: nil)
    }
}

