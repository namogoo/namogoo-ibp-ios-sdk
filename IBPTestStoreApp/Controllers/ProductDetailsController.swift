//
//  ProductDetailsController.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 18/10/2020.
//

import UIKit
import WebKit

class ProductDetailsController: UIViewController, Instantiable {
    struct ViewModel {
        let id: Int
        let image: String
        let title: String
        let description: String
        let price: Double
        let amount: Int
    }
    
    static var storyboardName: StringConvertible {
        return StoryboardName.main
    }
    
    var viewModel: ViewModel? {
        didSet {
            if let imageUrl = viewModel?.image, let url = NSURL(string: imageUrl) {
                productImage.loadImage(from: url)
            }
            productTitle.text = viewModel?.title
            productDescription.text = viewModel?.description
            productPrice.text = "\(viewModel?.price ?? 0)\(DataManager.shared.getCurrencySymbol())"
            productAmount.text = "\(viewModel?.amount ?? 0)"
            amountStepper.value = Double(viewModel?.amount ?? 1) // default is one product to be added
        }
    }
    
    private var webView: WKWebView!
    
    
    // MARK: - Outlets
    @IBOutlet weak var stackView: UIStackView!
    @IBOutlet weak var productImage: UIImageView!
    @IBOutlet weak var productTitle: UILabel!
    @IBOutlet weak var productDescription: UILabel!
    @IBOutlet weak var productPrice: UILabel!
    @IBOutlet weak var productAmount: UILabel!
    @IBOutlet weak var amountStepper: UIStepper!
    @IBOutlet weak var addToCartButton: UIButton!
    
    @IBAction func addToCartTapped(_ sender: Any) {
        guard let viewModel = viewModel,
              let amountString = productAmount.text,
              let amount = Int(amountString) else {
            return
        }
        DataManager.shared.updateCart(item: viewModel.id, amount: amount)
        self.navigationController?.popViewController(animated: true)
    }
    
    @IBAction func steppedValueChanged(_ sender: Any) {
        guard let stepper = sender as? UIStepper else {
            return
        }
        
        if stepper.value < 0 {
            stepper.value = 0
        } else if stepper.value > 5 {
            stepper.value = 5
        }
        productAmount.text = "\(Int(stepper.value))"
    }
    
    // MARK: - Life cycle
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        /* Only use for testing webview swizzling */
//        setupWebView()
    }
    
    // MARK: - Convenience
    private func setupWebView() {
        let configuration = WKWebViewConfiguration()
        
        let frame = CGRect(x: 0, y: 0, width: view.frame.size.width, height: view.frame.size.height)
        configuration.allowsInlineMediaPlayback = true
        configuration.mediaTypesRequiringUserActionForPlayback = .audio
        webView = WKWebView(frame: frame, configuration: configuration)
        view.addSubview(webView)
        
        webView.navigationDelegate = self
        webView.uiDelegate = self
        
        if let url = URL(string:"http://www.google.com") {
            let request = URLRequest(url: url)
            webView.load(request)
        }
    }
}

// MARK: WKWebView delegate methods
extension ProductDetailsController: WKNavigationDelegate, WKUIDelegate {

    func webView(_ webView: WKWebView, didFailProvisionalNavigation navigation: WKNavigation, withError error: Error) {
        let alert = UIAlertController(title: "Error", message:  error.localizedDescription, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .default,  handler: nil))
        present(alert, animated: true, completion: nil)
    }
    
    func webView(_ webView: WKWebView, createWebViewWith configuration: WKWebViewConfiguration, for navigationAction: WKNavigationAction, windowFeatures: WKWindowFeatures) -> WKWebView? {
        if navigationAction.targetFrame == nil {
            webView.load(navigationAction.request)
        }
        
        return nil
    }
}
