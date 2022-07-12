
## Create a new branch


```
git branch new-branch
```


## Add 

```
git fetch
```

```
git status
```

```
git add .
```

```
git commit -m "Short message for log."
```



## Change to a branch that is in the remote repository.

```
git checkout -t origin/other-branch
```


Merge branch into another branch.


First, make sure you move to the branch you want merge to stay. For example, the master branch:
```
git checkout master
```

Now merge with the other branch.

```
git merge other-branch
```



# Store credentials:

REVIEW THIS:


```
git config --global credential.helper store
```

```
git config --global user.email "Your@email.com"
```

```
git config --global user.name "Your Name"
```

## Delete a branch locally and remotelly
To delete  a localbranc

```
git branch -d local-branch
```

To delete a remote branch

```
git push origin --delete remote-branch
```

