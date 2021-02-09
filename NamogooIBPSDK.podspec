#
# Be sure to run `pod lib lint NamogooIBPSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'NamogooIBPSDK'
  s.version          = '0.1.1'
  s.summary          = 'Our NamogooIBPSDK helps eCommerce platforms give AI based incentives to their users.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
Namogoo is proud to present the iOS IBP SDK. With this SDK you can display AI based incentives to your customers. Please check us out at https://www.namogoo.com/intent-based-promotions/ to join, request a demo or set up your first campaign! The SDK supports iOS 11+ and uses Swift 5.1+ with Objc support.                       
DESC

  s.homepage         = 'https://github.com/namogoo/namogoo-ibp-ios-sdk.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'mngKali' => 'Kali.spassov@namogoo.com' }
  s.source           = { :git => 'https://github.com/namogoo/namogoo-ibp-ios-sdk/tree/master/NamogooIBPSDK.xcframework', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

  # s.source_files = 'NamogooIBPSDK.xcframework/*/*/Headers/*.{h,m,swift}'
  
  # s.resource_bundles = {
  #   'NamogooIBPSDK' => ['NamogooIBPSDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
