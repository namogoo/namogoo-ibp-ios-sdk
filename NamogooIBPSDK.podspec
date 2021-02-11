#
# Be sure to run `pod lib lint NamogooIBPSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'NamogooIBPSDK'
  s.version          = '0.1.2'
  s.summary          = 'Our NamogooIBPSDK helps eCommerce platforms give AI based incentives to their users.'

  s.description      = <<-DESC
Namogoo is proud to present the iOS IBP SDK. With this SDK you can display AI based incentives to your customers. Please check us out at https://www.namogoo.com/intent-based-promotions/ to join, request a demo or set up your first campaign! The SDK supports iOS 11+ and uses Swift 5.1+ with Objc support.                       
DESC

  s.homepage         = 'https://github.com/namogoo/namogoo-ibp-ios-sdk.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'mngKali' => 'Kali.spassov@namogoo.com' }
  s.source           = { :http => 'https://github.com/namogoo/namogoo-ibp-ios-sdk/raw/0.1.2/Distribution/NamogooIBPSDK.xcframework.zip' } 
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '11.0'
  s.vendored_frameworks = 'NamogooIBPSDK.xcframework'

  # s.source_files = 'NamogooIBPSDK.{xcframework}'
  
end
