atcoder abc resolver

# description
c++をビルドし、[atcoder](https://atcoder.jp/)の入力例と出力例とのテストを自動化するツールです。

# setup
bashで動作します。
rubyとg++が必要です。

# usage
[abc144_b](https://atcoder.jp/contests/abc144/tasks/abc144_b)を実施する場合、このファイルと同じディレクトリに`abc144_b.cpp`を作成後、下記のコマンドを実行します。
```
ruby resolver/resolv.rb abc144_b
```

## テストケースを増やす場合
`contest/abc144/abc144_b/`に入力する`input4.txt`と期待結果`output4.txt`を出力します。