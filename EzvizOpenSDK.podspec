Pod::Spec.new do |s|

  s.name         = 'EzvizOpenSDK'
  s.version      = '3.1'
  s.summary      = 'The library and public headers of EzvizOpenSDK'
  s.homepage     = 'https://open.ys7.com'
  s.license      = 'MIT'
  s.author       = { 'EzvizOpenSDK' => 'open-team@hikvision.com' }
  s.source       = { :git => 'https://github.com/Hikvision-Ezviz/SDK-iOS.git',:tag=>s.version.to_s}
  s.ios.deployment_target = '6.0'
  s.requires_arc = true
  s.public_header_files = 'Headers/*.h'
  s.vendored_library = 'libEZOpenSDK.a'
  s.library = 'stdc++.6.0.9'
  s.source_files = 'Headers/*h'
  s.frameworks = 'CoreMedia','AudioToolbox','MobileCoreServices','SystemConfiguration','OpenAL','GLKit','VideoToolbox'

end
