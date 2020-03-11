require "open-uri"
require "time"
CUR = __dir__ + '/../'
ARGV.map{|a| a.split(/[^a-z0-9_]+/)}.flatten.each do |number|
  match = number.match(/([a-z0-9]+)_([0-9a-z])/)
  contest = match[1]
  c = match[2]
  dir = "#{CUR}contest/#{contest}/#{number}/"
  # テストケースをダウンロードする
  unless File.exist?("#{dir}input1.txt")
    `mkdir -p #{dir}`
    match = open("https://atcoder.jp/contests/#{contest}/tasks/#{number}").read.match(
      /<h3>Sample Input 1<\/h3><pre>(.+)<\/pre>.*<h3>Sample Output 1<\/h3><pre>(.+)<\/pre>.*<h3>Sample Input 2<\/h3><pre>(.+)<\/pre>.*<h3>Sample Output 2<\/h3><pre>(.+)<\/pre>.*<h3>Sample Input 3<\/h3><pre>(.+)<\/pre>.*<h3>Sample Output 3<\/h3><pre>(.+)<\/pre><\/section>\r?\n<\/div>/m
    )
    3.times do |i|
      File.open("#{dir}input#{i + 1}.txt", "w") do |f| 
        f.puts(match[i * 2 + 1])
      end
      File.open("#{dir}output#{i + 1}.txt", "w") do |f| 
        f.puts(match[i * 2 + 2])
      end
    end
  end

  ## コンパイルする
  path = `#{CUR}build.sh #{number}.cpp`
  i = 1
  while File.exist?("#{dir}input#{i}.txt")
    print "#{i}: "
    time = Time.now
    result = `cat #{dir}input#{i}.txt | #{path}`
    expected = open("#{dir}output#{i}.txt").read
    if result.chomp == expected.chomp
      puts "AC #{(Time.now.usec - time.usec) / 1000}ms"
    else
      puts "WA"
      puts "Expected:"
      puts expected
      puts "Result:"
      puts result
    end
    puts "-" * 5
    i += 1
  end
end