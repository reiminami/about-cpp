# ライブラリ

## 目次

1. [【外部】 about-c/string.h](https://github.com/reiminami/about-c?tab=readme-ov-file#stringh-%E6%96%87%E5%AD%97%E5%88%97%E6%93%8D%E4%BD%9C)
1. [【外部】 about-c/time.h](https://github.com/reiminami/about-c?tab=readme-ov-file#timeh-%E6%99%82%E9%96%93)
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

- イテレータ
    - find - 指定値と同じ値の要素へのイテレータ
    - is_sorted_until - 昇順になっていない要素へのイテレータ
    - min_element - 最大値の要素へのイテレータ
    - max_element - 最小値の要素へのイテレータ
    - lower_bound - 指定値以上の要素へのイテレータ
    - upper_bound - 指定値より大きい要素へのイテレータ
    - find_first_of - 随時検索
    - find_if - 条件一致する最初の要素へのイテレータ

    ```cpp
    bool lessThan40(int value) {
        return value < 40;
    }

    vector<int> nums = {40, 50, 10, 20, 30};

    auto iter1 = find(nums.begin(), nums.end(), 10);
    if (iter1 != nums.end()) {
        cout << "Found: " << *iter1 << endl;
    }
    auto iter2 = is_sorted_until(nums.begin(), nums.end());
    cout << *iter2 << endl;
    auto iter3 = min_element(nums.begin(), nums.end());
    cout << *iter3 << endl;
    auto iter4 = max_element(nums.begin(), nums.end());
    cout << *iter4 << endl;
    auto iter5 = lower_bound(nums.begin(), nums.end(), 20);
    cout << *iter5 << endl;
    auto iter6 = upper_bound(nums.begin(), nums.end(), 20);
    cout << *iter6 << endl;
    vector<int> tmps = {60, 70, 20, 10};
    auto iter7 = find_first_of(nums.begin(), nums.end(), tmps.begin(), tmps.end());
    cout << *iter7 << endl;
    auto iter8 = find_if(nums.begin(), nums.end(), lessThan40);
    cout << *iter8 << endl;
    ```

- 置換
    - replace - 指定値を別の値に置換
    - replace_copy - replaceしたコピー作成
    - replace_copy_if - 条件付きで、replaceしたコピー作成
    - replace_if - 条件付きでrelpace

    ```cpp
    bool lessThan40(int value) {
        return value < 40;
    }

    vector<int> nums = {50, 10, 30, 20, 40};
    vector<int> nums2(5);
    vector<int> nums3(5);

    replace(nums.begin(), nums.end(), 50, 60);
    replace_copy(nums.begin(), nums.end(), nums2.begin(), 60, 70);
    replace_copy_if(nums.begin(), nums.end(), nums3.begin(), lessThan40, 99);
    replace_if(nums.begin(), nums.end(), lessThan40, 0);
    ```

- 交換
    - swap - ２つの変数の値を交換
    - swap_ranges - ２つの配列の指定範囲の要素を交換

    ```cpp
    int a = 10;
    int b = 20;
    swap(a, b);

    vector<int> x = {10, 20, 30};
    vector<int> y = {97, 98, 99, 40, 50};
    // x[0] ~ x[2]と、y[0] ~ y[2]を交換
    swap_ranges(x.begin(), x.end(), y.begin());
    ```

- 判定
    - all_of - 全ての要素が条件に一致するか？
    - any_of - いずれかの要素が条件に一致するか？
    - none_of - どの条件も一致しないか？
    - is_sorted - 昇順か？
    - includes - ２つのソート済み配列で、配列Aが配列Bの要素を全て持っているか？
    - is_permutation - 片方の順列がもう片方に存在するか？

    ```cpp
    vector<int> nums = {10, 20, 30, 40};

    cout << all_of(nums.begin(), nums.end(), lessThan40) << endl;
    cout << any_of(nums.begin(), nums.end(), lessThan40) << endl;
    cout << none_of(nums.begin(), nums.end(), lessThan40) << endl;
    cout << is_sorted(nums.begin(), nums.end()) << endl;

    vector<int> tmps = {20, 40};
    cout << includes(nums.begin(), nums.end(), tmps.begin(), tmps.end()) << endl;   // 1
    cout << includes(tmps.begin(), tmps.end(), nums.begin(), nums.end()) << endl;   // 0

    vector<int> others = {40, 30, 20, 10};
    cout << is_permutation(nums.begin(), nums.end(), others.begin(), others.end()) << endl;
    ```

- 検索
    - binary_search - ソート済みデータへの効率的な検索
    - search - 別のデータで指定された値のシーケンスを検索

    ```cpp
    vector<int> nums    = {10, 30, 50, 70};
    vector<int> targets = {10, 30, 50, 80};

    cout << binary_search(nums.begin(), nums.end(), 30) << endl;
    cout << (search(nums.begin(), nums.end(), targets.begin(), targets.end())!= nums.end());
    ```

- ソート
    - sort - 昇順
    - reverse - 逆順
    - reverse_copy - 逆順要素のコピー

    ```cpp
    vector<int> nums = {40, 10, 20, 30};
    vector<int> tmps(4);

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    reverse_copy(nums.begin(), nums.end(), tmps.begin());
    ```

- その他
    - count - 指定値の出現回数
    - count_if - 条件一致する値の出現回数
    - copy - コピー
    - fill - 指定値でデータ範囲を埋める
    - merge - ２つのデータをマージしてコピー
    - for_each - 全要素に関数を実行

    ```cpp
    bool lessThan40(int value) {
        return value < 40;
    }

    void plusOne(int &value) {
        value++;
    }

    vector<int> nums = {40, 10, 20, 30};
    vector<int> tmps(4);
    vector<int> merged(8);

    cout << count(nums.begin(), nums.end(), 10) << endl;
    cout << count_if(nums.begin(), nums.end(), lessThan40) << endl;
    copy(nums.begin(), nums.end(), tmps.begin());
    fill(tmps.begin(), tmps.end(), 99);
    merge(nums.begin(), nums.end(), tmps.begin(), tmps.end(), merged.begin());
    for_each(nums.begin(), nums.end(), plusOne);
    ```

[⬆︎目次へ戻る](#目次)

## bit

- `x & y` - xとyの論理積
- `x | y` - xとyの論理和
- `x ^ y` - xとyの排他的論理和
- `~x` - xの1の補数
- `x << 1` - 左シフト
- `x >> 1` - 右シフト

[⬆︎目次へ戻る](#目次)
