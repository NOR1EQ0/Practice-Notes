#!/usr/bin/env bash
# setup-git-hooks.sh
# Register git hooks by pointing core.hooksPath to the git-hooks/ directory.
# This avoids copying files and keeps hooks version-controlled.

set -euo pipefail

REPO_ROOT="$(git rev-parse --show-toplevel)"
HOOKS_DIR="${REPO_ROOT}/git-hooks"

# Verify that the hooks directory exists
if [[ ! -d "$HOOKS_DIR" ]]; then
    echo "[ERROR] Hooks directory not found at ${HOOKS_DIR}"
    exit 1
fi

# Point git to use git-hooks/ as the hooks directory
git config --local core.hooksPath "$HOOKS_DIR"

echo "[OK] Git hooks registered successfully."
echo "     core.hooksPath = ${HOOKS_DIR}"
echo ""
echo "Active hooks:"
ls -1 "$HOOKS_DIR" | grep -v '\.sh$' || echo "     (none found - make sure hook files have no .sh extension)"