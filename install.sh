#! /bin/sh

# TODO: INSTALL MYSQL AND POSTGRESQL

sudo apt-get -y update

# Oh my zsh
sudo apt-get -y install zsh
chsh -s /usr/bin/zsh
sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
zsh --version > setup.log

# Feh
sudo apt-get -y install feh

# Java
sudo add-apt-repository ppa:webupd8team/java
sudo apt-get -y update
sudo apt-get -y install oracle-java8-installer
java -version >> setup.log

### Install hidden files and directories ###

cd $HOME && echo "Going to $HOME..." >> setup.log
# Loop over files
for file in $(ls -a $OLDPWD); do
  case "$file" in
    ".git")         echo "Ignoring .git";;
    ".gitignore")   echo "Ignoring .gitignore";;
    "$0")           echo "Ignoring $0";;
    # Make symlinks from git repository to $HOME
    *)              ln -sf "$OLDPWD/$file";;
  esac
done

# Install vim and its components before bundles
sudo apt-get -y install vim vim-nox vim-gtk vim-gnome vim-athena
# Neobundle -> neocomplete, vim-airline
curl https://raw.githubusercontent.com/Shougo/neobundle.vim/master/bin/install.sh | sh

source ~/.bashrc
source ~/.zshrc

echo "\n----- TODO -----\n"

echo "Install IntelliJIdea"
echo "Install Gimp"
echo "Download Monaco font and reload ~/.fonts/Monaco into account"
echo "Setup ssh\n"

echo "----- Optionals -----\n"

echo "Retrieve lessons and projects from bitbucket repositories"
echo "Install i3 (if necessary)"
echo "Get an image background"

echo "Install Brackets\n"
