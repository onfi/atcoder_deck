require "open-uri"
require "time"
CUR = __dir__ + '/../'
ARGV.each do |number|
  number = number.sub(/\.cpp$/, '')
  match = number.match(/([a-z0-9]+)_([0-9a-z])/)
  contest = match[1]
  c = match[2]
  dir = "#{CUR}contest/#{contest}/#{number}/"
  # テストケースをダウンロードする
  unless File.exist?("#{dir}input1.txt")
    puts "load a sample from https://atcoder.jp/contests/#{contest}/tasks/#{number}"
    unless File.exist?("#{CUR}tmp/#{number}.html")
      `mkdir -p #{CUR}tmp`
      File.open("#{CUR}tmp/#{number}.html", "w") do |f| 
        f.puts(open("https://atcoder.jp/contests/#{contest}/tasks/#{number}").read)
      end
    end
    html = open("#{CUR}tmp/#{number}.html").read
    i = 1
    `mkdir -p #{dir}`
    while true
      match = html.match(
        /<h3>Sample Input #{i}<\/h3>.*<pre>(.+)<\/pre>.*<h3>Sample Output #{i}<\/h3>[:space:]*<pre>([^<]+)<\/pre>/m
      )
      break unless match
      File.open("#{dir}input#{i}.txt", "w") do |f| 
        f.puts(match[1])
      end
      File.open("#{dir}output#{i}.txt", "w") do |f| 
        f.puts(match[2])
      end
      i += 1
    end
  end

  ## コンパイルする
  path = `#{CUR}build_zapcc.sh #{number}.cpp`
  i = 1
  while File.exist?("#{dir}input#{i}.txt")
    print "#{i}: "
    time = Time.now
    result = `cat #{dir}input#{i}.txt | #{path}`
    expected = open("#{dir}output#{i}.txt").read
    if result.chomp.gsub(/\r?\n/, "\n") == expected.chomp.gsub(/\r?\n/, "\n")
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