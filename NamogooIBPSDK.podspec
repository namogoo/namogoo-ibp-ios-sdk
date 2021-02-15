#
# Be sure to run `pod lib lint NamogooIBPSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'NamogooIBPSDK'
  s.version          = '0.1.4'
  s.summary          = 'Our NamogooIBPSDK helps e-commerce sites give personal promotions to the site visitors, based on machine learning decisions.'

  s.description      = <<-DESC
Welcome to Namogoo IBP's iOS SDK. With this SDK you can display AI based incentives to your visitors. Please check us out at https://www.namogoo.com/intent-based-promotions/ to join, request a demo or set up your first campaign! The SDK supports iOS 11+ and uses Swift 5.1+ with full ObjectiveC support.                       
DESC

  s.homepage         = 'https://github.com/namogoo/namogoo-ibp-ios-sdk.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Namogoo Platform' => 'mobile.dev@namogoo.com' }
  s.source           = { :git => 'https://github.com/namogoo/namogoo-ibp-ios-sdk.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '11.0'
  s.vendored_frameworks = 'NamogooIBPSDK.xcframework'
  
end
