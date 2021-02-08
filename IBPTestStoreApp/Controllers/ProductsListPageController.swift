//
//  ProductsListPageController.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 14/10/2020.
//

import UIKit

class ProductsListPageController: UIViewController, Instantiable, UISearchBarDelegate {
    
    static var storyboardName: StringConvertible {
        return StoryboardName.main
    }

    private static let sectionInsets = UIEdgeInsets(top: 10.0,
                                                    left: 10.0,
                                                    bottom: 2.0,
                                                    right: 10.0)
    
    
    
    // MARK: - Outlets
    @IBOutlet weak var productsCollection: UICollectionView!
    
    var products: [ProductModel] = []
    var searchController: UISearchController?
    var filterBy: String?
    var filtered: (String?, [ProductModel]) = (nil, [])
    // MARK: - Life cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        productsCollection.delegate = self
        productsCollection.dataSource = self
        
//        searchController = UISearchController(searchResultsController: self)
//        searchController?.searchResultsUpdater = self
//
//        searchBar.delegate = self
        let search = UISearchController(searchResultsController: nil)
        search.searchResultsUpdater = self
        search.obscuresBackgroundDuringPresentation = false
        search.searchBar.placeholder = "Type something here to search"
        navigationItem.searchController = search
        
        
        
    }
    
    // MARK: - Convenience
    
    func getFiltered() -> [ProductModel] {
        guard let filterBy = filterBy, filterBy.count > 0 else {
            return products
        }
        
        if filterBy == filtered.0 {
            return filtered.1
        } else {
            let filteredProducts = products.filter({ $0.title.lowercased().contains(filterBy.lowercased()) })
            filtered = (filterBy, filteredProducts)
            return filteredProducts
        }
    }
}

extension ProductsListPageController: UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return getFiltered().count
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let width: CGFloat = (view.bounds.width / 2.0) - 20
        let height: CGFloat = 200.0
        
        return CGSize(width: width, height: height)
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, insetForSectionAt section: Int) -> UIEdgeInsets {
        return ProductsListPageController.sectionInsets
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        guard let cell = collectionView.dequeueReusableCell(withReuseIdentifier: ProductCell.reuseIdentifier,
                                 for: indexPath) as? ProductCell else {
                                    return UICollectionViewCell()
        }
        
        let productsFilteres = getFiltered()
        
        let data = productsFilteres[indexPath.row]
        cell.viewModel = ProductCell.ViewModel(image: data.image, title: data.title, subTitle: "\(data.price)\(DataManager.shared.getCurrencySymbol())")
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        let productsFilteres = getFiltered()
        
        let data = productsFilteres[indexPath.row]
        
        if products.count > 0 {
            let vc = ProductDetailsController.instantiateFromStoryboard()
            let amount = DataManager.shared.checkCart(item: data.id)
            
            self.navigationController?.pushViewController(vc, animated: true)
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.1, execute: {
                vc.viewModel = ProductDetailsController.ViewModel(id: data.id, image: data.image, title: data.title, description: data.description, price: data.price, amount: amount > 0 ? amount : 1)
            })
            
        }
    }
}

extension ProductsListPageController: UISearchResultsUpdating {
  func updateSearchResults(for searchController: UISearchController) {
    guard let text = searchController.searchBar.text, text != filterBy else { return }
    
    if text.count > 0 {
        filterBy = text
        productsCollection.reloadData()
    } else if filterBy != nil {
        filterBy = nil
        productsCollection.reloadData()
    }
  }
}
