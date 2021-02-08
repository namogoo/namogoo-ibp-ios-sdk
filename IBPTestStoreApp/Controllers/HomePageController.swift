//
//  HomePageController.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 18/10/2020.
//

import UIKit

class HomePageController: UIViewController {
        
    // MARK: - Outlets
    @IBOutlet weak var bannersCollection: UICollectionView!
    @IBOutlet weak var searchButton: UIButton!
    @IBOutlet weak var currencyControl: UISegmentedControl!
    
    
    @IBAction func currencyControlValueChanged(_ sender: Any) {
        guard let control = sender as? UISegmentedControl else { return }
        switch control.selectedSegmentIndex {
        case 0:
            DataManager.shared.setCartCurrency(to: "USD")
        case 1:
            DataManager.shared.setCartCurrency(to: "EUR")
        default:
            break;
        }
    }
    
    @IBAction func searchTapped(_ sender: Any) {
        if let rootVC = UIApplication.shared.getTabController(),
           let navController = rootVC.viewControllers?[1] as? UINavigationController,
           let catsVC = navController.viewControllers.first as? CategoriesSelectionController {
            rootVC.selectedIndex = 1
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.1, execute: {
                catsVC.setSelection(item: 0)
            })
        }
    }
    
    
    // MARK: - Life cycle
    override func viewDidLoad() {
        bannersCollection.delegate = self
        bannersCollection.dataSource = self
        
        NotificationCenter.default.addObserver(forName: DataManager.Events.categoriesUpdated, object: nil, queue: nil) { notification in
            self.reloadCollection()
        }
    }
    
    
    // MARK: - Convenience
    func reloadCollection() {
        DispatchQueue.main.async {
            self.bannersCollection.reloadData()
        }
    }
    
}

extension HomePageController: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        DataManager.shared.store.categories.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        guard let cell = collectionView.dequeueReusableCell(withReuseIdentifier: HomeBanner.reuseIdentifier,
                                 for: indexPath) as? HomeBanner else {
                                    return UICollectionViewCell()
        }
        
        let data = DataManager.shared.store.categories[indexPath.row]
        cell.viewModel = HomeBanner.ViewModel(image: data.bannerImage, text: data.name)
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        if let rootVC = UIApplication.shared.getTabController(),
           let navController = rootVC.viewControllers?[1] as? UINavigationController,
           let catsVC = navController.viewControllers.first as? CategoriesSelectionController {
            rootVC.selectedIndex = 1
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.1, execute: {
                catsVC.setSelection(item: indexPath.row + 1)
            })
        }        
    }
}
