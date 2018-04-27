def subdomain_visits(cpdomains)
  domain_hits = Hash.new { |hash, v| hash[v] = 0 }

  cpdomains.each do |cpdomain|
    count, domain = cpdomain.split(' ')

    count = count.to_i
    fields = domain.split('.')
    (0..fields.length - 1).each do |i|
      domain_hits[fields[i..fields.length - 1].join('.')] += count
    end
  end

  domain_hits.map do |key, value|
    "#{value} #{key}"
  end.to_a
end
