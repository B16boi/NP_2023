# NP_2023

### Using Git and Github

1. Install git on your machine using 

```
sudo apt install git
```

2. Make sure **no directory named NP_2023** in your workspace directory .

3. Clone this repo using the following command, then this repo will be cloning into your workspace named NP_2023.

```
git clone https://github.com/JYYehlouis/NP_2023.git
``` 

4. Open your terminal and cd to this directory, set your personal info with 

```
git config --local user.name "<Yourname>" && git config --local user.email "<YourEmail>"
```

5. Set up your depository as origin, using 

```
git remote add origin https://github.com/JYYehlouis/NP_2023.git
```

6. For personal convenience, I recommend using this command next, 

```
git remote set-url origin https://<YourGithubUsername>:<YourToken>@github.com/JYYehlouis/NP_2023.git
```

7. Before working on this repo, it is a good habit to check if you are using the latest repo, using the command below to update all your files.

```
git fetch origin && git pull
```

8. Using the following command if you have to work on some specific branch,

```
git switch <branch-name>
```

9. After working on this repo, you will have to commit this changes, using the following commands, and the ```<message>``` is used to tell others what you changed.

```
git add . && git commit -m "<message>"
```

10. Using the following command after point 8, this will help you upload you changes, and you have to push the branch correctly on the name (usually the same as you see using ```git status```). 

```
git push -u origin <branch-name>
```

### Compilation

```
g++ -O2 -L"\usr\include\SFML" -lsfml-graphics -lsfml-window -lsfml-system
```

### Current status

1. Completed the functionality of Main Screen and Game Screen. Next goal: connect both elements.

2. Completed the gameplay detection and communicatiton of Game Board. Next goal: complete the In-Game Chat Box.

### Complete (git log to see the progress)
