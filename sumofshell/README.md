rm -rf $HOME/.brew
git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew
echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc
source $HOME/.zshrc
brew update
brew install readline
brew info readline

READLINE_FALG와 .c.o의 닉네임 본인 닉네임으로 변경.