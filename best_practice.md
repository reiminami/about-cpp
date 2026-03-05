# ベストプラクティス

## `_`で始まる名前はつけない

予約語と名前衝突する可能性があります。

## 命名ルール

スコープが小さい変数を除き、以下のルールは極力守りましょう。

- 命名規則に則る
- 略称をなるべく使わない (例: `buf` -> `buffer`)
- ハンガリアン記法を使わない (例: `m_value` -> `value`)
- 40文字を超えない長さ
- わかりやすい名前
    - 機能の目的が明確
    - 動作や情報にふさわしい

- 動作やクラス、情報にふさわしい名前をつける

## ヘッダファイルで`using` を使わない

`using` を使用したヘッダファイルを読み込んだソースの名前空間が汚染されます。

## インクルードガードを使用する

同じヘッダファイルを複数回インクルードする問題を回避できます。

```cpp
// Bad
void Hello();

// Good
#ifndef F_HPP_
#define F_HPP_

void Hello();

#endif
```

## メンバ変数の初期化リストを使用する

```cpp
// Bad
class MyClass {
public:
    MyClass(int value) {
        value_ = value;
    }
private:
    int value_;
};

// Good
class MyClass {
public:
    MyClass(int value) : value_(value) {}
private:
    int value_;
};
```

## メンバ変数にデフォルト値を割り当てる

メンバ変数の初期化を忘れると、未定義の動作にバグが発生する原因となります。

```cpp
private:
    int value_ = 0;
```

## 波カッコでデフォルト値の割り当て

初期化には`{}`を優先して使用しましょう。

```cpp
private:
    int value_ {0};
```

## テンプレートを積極的に使用する

テンプレートはマクロより優先されるべきです。
