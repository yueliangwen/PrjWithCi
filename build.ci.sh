#!/bin/sh
set -e -x

export PATH="$PATH:/usr/local/bin"

tasks=(
clean.sh
make.sh
ut.sh
cov.sh
)

CUR_DIR=$WORKSPACE
for t in ${tasks[@]} ; do set -x ; echo $PWD; [ -x $CUR_DIR/tasks.ci/$t ] && { $CUR_DIR/tasks.ci/$t; } ; set +x ; done

echo "WORKSPACE: "$WORKSPACE
echo "NODE_NAME: "$NODE_NAME
echo "NODE_LABELS :"$NODE_LABELS

exit 0
