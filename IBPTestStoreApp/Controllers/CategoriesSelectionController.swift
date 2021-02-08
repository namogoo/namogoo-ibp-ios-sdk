//
//  CategoriesSelectionCollection.swift
//  IBPTestStoreApp
//
//  Created by Kali Spassov on 14/10/2020.
//

import UIKit

class CategoriesSelectionController: UIViewController {
    // MARK: - Outlets
    @IBOutlet weak var categoriesTable: UITableView!
    
    
    // MARK: - Life cycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        categoriesTable.delegate = self
        categoriesTable.dataSource = self
        
        categoriesTable.estimatedRowHeight = 80
        categoriesTable.rowHeight = UITableView.automaticDimension
        
        NotificationCenter.default.addObserver(forName: DataManager.Events.categoriesUpdated, object: nil, queue: nil) { notification in
            self.reloadTable()
        }
    }
    
    // MARK: - Convenience
    func reloadTable() {
        DispatchQueue.main.async {
            self.categoriesTable.reloadData()
        }
    }
    
    func setSelection(item: Int) {
        tableView(categoriesTable, didSelectRowAt: IndexPath(item: item, section: 0))
    }
    
}

extension CategoriesSelectionController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return DataManager.shared.store.categories.count + 1
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: CategoryCell.identifier, for: indexPath) as? CategoryCell else {
            return UITableViewCell()
        }
        
        let data: CategoryModel!
        if indexPath.row == 0 {
            data = CategoryModel(bannerImage: UIImage(), name: "All")
        } else {
            data = DataManager.shared.store.categories[indexPath.row - 1]
        }
        
        cell.viewModel = CategoryCell.ViewModel(title: data.name)
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let products: [ProductModel]!
        if indexPath.row == 0 {
            products = DataManager.shared.store.products
        } else {
            let category = DataManager.shared.store.categories[indexPath.row - 1]
            products = DataManager.shared.store.products.filter({ $0.category == category.name })
        }
        
        
        if products.count > 0 {
            let vc = ProductsListPageController.instantiateFromStoryboard()
            vc.products = products
            
            self.navigationController?.pushViewController(vc, animated: true)
        }
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return UITableView.automaticDimension
    }
}
