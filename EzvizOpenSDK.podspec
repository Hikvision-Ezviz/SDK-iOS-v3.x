Pod::Spec.new do |s|

  s.name         = 'EzvizOpenSDK'
  s.version      = '3.1'
  s.summary      = 'Ezviz Open SDK '
  s.homepage     = 'https://open.ys7.com'
  s.license      = 'MIT'
  s.author   =   { 'EzvizOpenSDK' => 'open-team@hikvision.com' }
  s.source   =   { :git => 'https://github.com/openboy2012/SDK-iOS.git',:tag=>s.version.to_s}
  s.ios.deployment_target = '6.0'
  s.public_header_files = 'Headers/*.h'
  s.requires_arc = true
  s.vendored_library = 'libEZOpenSDK.a'
  s.library = 'stdc++.6.0.9'
  s.source_files = 'Headers/*h'
  s.frameworks = 'CoreMedia','AudioToolbox','MobileCoreServices','SystemConfiguration','OpenAL','GLKit','VideoToolbox'

  s.subspec 'OpenSSL' do |ss|
    ss.source_files = 'openssl/include/*.h'
    ss.vendored_libraries = 'openssl/lib/libcrypto.a','openssl/lib/libssl.a'
  end

end
