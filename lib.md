# ライブラリ

## トピック

1. [about-c/string.h (別リポジトリ)](https://github.com/reiminami/about-c?tab=readme-ov-file#stringh-%E6%96%87%E5%AD%97%E5%88%97%E6%93%8D%E4%BD%9C)
1. [about-c/time.h (別リポジトリ)](https://github.com/reiminami/about-c?tab=readme-ov-file#timeh-%E6%99%82%E9%96%93)

## 目次

1. [iostream](#iostream) - 標準入出力
1. [fstream](#fstream) - ファイル
1. [cmath](#cmath) - 数学
1. [string](#string) - 文字列
1. [algorithm](#algorithm) - アルゴリズム
1. [(bit)](#bit) - ビット

[⬆︎目次へ戻る](#目次)

## iostream

```cpp
// ユーザー入力の読み取り
string name;
cout << "Input: ";
cin >> name;
cout << name << endl;

// 複数入力
int height;
int weight;
cout << "input height and weight: ";
cin >> height >> weight;
cout << "HEIGHT: " << height << endl;
cout << "WEIGHT: " << weight << endl;

// 一行入力
string line;
cout << "input: ";
cin.ignore();
getline(cin, line);

// cout - データを出力する
// cerr - エラーメッセージを出力する
// clog - ログメッセージを出力する
// wcout - wcharを使用したcout
// wcerr - wcharを使用したcerr
// wclog - wcharを使用したclog
// wcin - wcharを使用したcin
```

[⬆︎目次へ戻る](#目次)

## fstream

```cpp
// filebuf (ファイルの読み書きに使用されるクラス)
filebuf fb;
fb.open("test.txt", ios_base::out);
fb.sputn("Hello, World", 13);
fb.close();

// fstraem (ファイルの読み取りと書き込みに使用されるクラス)
fstream f("test.txt");
f << "hello world";

string txt;
getline(f, txt);
cout << txt;

f.close();

// ifstream (ファイルからの読み取りに使用されるクラス)
string txt;
ifstream rf("test.txt");

while (getline(rf, txt)) {
    cout << txt;
}

rf.close();

// ofstream (ファイルへの書き込みに使用されるクラス)
ofstream f("test.txt");
f << "hey";
f.close();

// 追記
ofstream f("test.txt", ios::app);
f << "hey";
f.close();
```

[⬆︎目次へ戻る](#目次)

## cmath

```cpp
cout << abs(-4) << endl;    // 絶対値
cout << ceil(1.1) << endl;  // 最も近い整数に切り上げ
cout << floor(1.9) << endl; // 最も近い整数に切り捨て
cout << round(2.5) << endl; // 最も近い整数へ丸める
cout << trunc(1.9) << endl; // 整数部分を返す
// fabs - 絶対値を返す
// fmax - 最大値を返す
// fmin - 最小値を返す
// fmod - 余りを返す
// hypot - 原点(0, 0)からの2dポイント(x, y)の距離を返す
// pow - べき乗を返す
// remainder - 剰余を返す
```

[⬆︎目次へ戻る](#目次)

## string

- 文字検索

```cpp
string txt = "Hello World";
cout << txt.back() << endl;         // 末尾の文字にアクセス
cout << txt.front() << endl;        // 先頭の文字にアクセス
cout << txt.find("o") << endl;      // 文字列[0]の最初の出現位置
cout << txt.rfind("o") << endl;     // 文字列[0]の最後の出現位置
cout << txt.at(1) << endl;          // 指定位置[0]の文字
cout << txt.substr(3) << endl;      // 開始位置[0]から最後までの文字列
cout << txt.substr(3, 4) << endl;   // 開始位置[0]から文字数[1]までの文字列
// begin - 先頭の要素を示すイテレータを返す
// end - 末尾の要素を示すイテレータを返す
```

- 文字変換

```cpp
string txt = "Hello World";
txt.append("!!!");                  // 文字列の末尾に文字列[0]を追加
txt.erase(4);                       // 指定位置[0]以降の文字を削除
cout << txt.replace(2, 3, "y");     // 位置[0]から文字数[1]分を別の文字[2]に置換
txt.swap(world);                    // 2つの文字列の内容を交換
// insert - 指定位置に文字列を挿入する
// pop_back - 文字列の末尾の文字を削除する
// push_back - 文字列の末尾に文字を追加する
```

- 文字サイズ関連

```cpp
string txt = "Hello World";
cout << txt.empty() << endl;        // 文字列が空か？
txt.resize(5);                      // 文字列のサイズを変更
cout << txt.length();               // 文字列の長さ
// size - lengthと同様
```

[⬆︎目次へ戻る](#目次)

## vector

イテレータは[コンテナ (README.md)](/README.md#コンテナ) 参照
メモリ関連は`capacity`, `reserve`, `shrink_to_fit` を調べる
サイズ関連は`empty`, `resize`, `size`, `max_size` を調べる

- 追加/削除

```cpp
vector<string> colors = {"red", "green", "yellow"};
colors.clear();                             // 内容をクリア
colors.erase(colors.begin() + 1);           // 要素[0]を削除
colors.insert(colors.begin() + 1, "cyan");  // 位置[0]に要素[1]を挿入
colors.pop_back();                          // 末尾の要素を取り出す
colors.push_back("pink");                   // 末尾に要素を追加
nums2.assign(nums1.begin(), nums1.end());   // ベクターを別のベクターにコピー
colors1.swap(colors2);                      // 2つのベクターの内容を交換
```

- 参照

```cpp
vector<string> colors = {"red", "green", "yellow"};
cout << colors.at(1);                       // 指定位置[0]の要素を参照
cout << colors.back() << endl;              // 末尾の要素を返す
cout << colors.front() << endl;             // 先頭の要素を返す
string* d = colors.data();                  // 要素を指すメモリブロックのポインタを返す
```

[⬆︎目次へ戻る](#目次)

## algorithm

- [all_of](/algorithm/all_of.cpp) - 各要素が条件に一致するか？
- [any_of](/algorithm/any_of.cpp) - 要素のいずれかが条件に一致するか？
- [binary_search](/algorithm/binary_search.cpp) - ソート済みデータへの効率的な検索
- [copy](/algorithm/copy.cpp) - 内容をコピー
- [count](/algorithm/count.cpp) - 指定値の出現回数
- [count_if](/algorithm/count_if.cpp) - 条件に一致する値の出現回数
- [fill](/algorithm/fill.cpp) - 指定値でデータ範囲を埋める
- [find](/algorithm/find.cpp) - 指定値の最初の出現位置を指すイテレータ
- [find_first_of](/algorithm/find_first_of.cpp) - 随時検索 (ない場合データ末尾)
- [find_if](/algorithm/find_if.cpp) - 条件一致する最初の値 (ない場合データ末尾)
- find_if_not - find_ifの逆
- [for_each](/algorithm/for_each.cpp) - 全要素に関数実行
- [includes](/algorithm/includes.cpp) - ソート済みデータを別データの値で検索し、全て見つかるか？
- [is_permutation](/algorithm/is_permutation.cpp) - データの順列が別データに存在するか？
- [is_sorted](/algorithm/is_sorted.cpp) - データが昇順で並べられているか？
- [is_sorted_until](/algorithm/is_sorted_until.cpp) - 昇順になっていない最初の値へのイテレータ
- [lower_bound](/algorithm/lower_bound.cpp) - ソート済みデータで、指定値より小さい最初の要素へのイテレータ
- [max_element](/algorithm/max_element.cpp) - データ内の最大値へのイテレータ
- [merge](/algorithm/merge.cpp) - ２つのデータの値をマージして別データにコピー
- [min_element](/algorithm/min_element.cpp) - データ内の最小値へのイテレータ
- [none_of](/algorithm/none_of.cpp) - 各要素が条件に一致しないか？
- [replace](/algorithm/replace.cpp) - 指定値を別の値に置換
- [replace_copy](/algorithm/replace_copy.cpp) - 指定値を別の値に置換したコピーを作成
- [replace_copy_if](/algorithm/replace_copy_if.cpp) - 条件に一致した値を別の値に置換したコピーを作成
- [replace_if](/algorithm/replace_if.cpp) - 条件に一致した値を別の値に置換
- [reverse](/algorithm/reverse.cpp) - 要素を逆順にする
- [reverse_copy](/algorithm/reverse_copy.cpp) - 要素を逆順にしたコピーを作成
- [search](/algorithm/search.cpp) - 別のデータで指定された値のシーケンスを検索
- [sort](/algorithm/sort.cpp) - 要素を昇順にする
- [swap](/algorithm/swap.cpp) - ２つの変数の値を交換する
- [swap_ranges](/algorithm/swap_ranges.cpp) - データの値を同じサイズの別データの値と交換
- [upper_bound](/algorithm/upper_bound.cpp) - ソート済みデータで、指定値より大きい最初の要素へのイテレータ

[⬆︎目次へ戻る](#目次)

## bit

- `x & y` - xとyの論理積
- `x | y` - xとyの論理和
- `x ^ y` - xとyの排他的論理和
- `~x` - xの1の補数
- `x << 1` - 左シフト
- `x >> 1` - 右シフト

[⬆︎目次へ戻る](#目次)
