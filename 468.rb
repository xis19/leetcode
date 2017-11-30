def valid_ip_address(ip)
  if ip =~ /^((0|([1-9][0-9]{0,2}))\.){3}(0|([1-9][0-9]{0,2}))$/
    ip.split('.').map { |i| i.to_i}.all? { |i| i < 256} ? 'IPv4' : 'Neither'
  elsif ip =~ /^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$/
    'IPv6'
  else
    'Neither'
  end 
end
