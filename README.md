# Encrypt

A simple file encryption tool utilizing xor.

## Installation

```bash
gh repo clone r2dev2/Encrypt
cd Encrypt
gcc -o encrypt encrypt.c
```

and then copy encrypt binary to a folder which is in your path (eg. `~/.local/bin` or `/usr/bin`)

## Usage

### Encrypt a file

```bash
encrypt -i filetoencrypt -o encryptedfile # get input from filetoencrypt
encrypt -o encryptedfile # get input from stdin
encrypt # get input from stdin and output to stdout
```

### Decrypt a file

```bash
encrypt -i filetodecrypt -o decryptedfile # get input from filetodecrypt
encrypt -o decryptedfile # get input from stdin
encrypt # get input from stdin and output to stdout
```

## Security

Yea this is literally just a simple xor with your password and the bytes of the file. If your file has a predictable sequence of bytes (eg. a pdf or a jpg), it is ridiculously easy to crack ur password (unless ur password is like 50 characters long).

If your file is all raw data that is all unpredictable (eg. a message or an important number), it would be fairly hard to crack the message. However, DO NOT (and I repeat DO NOT) use this for actually important communications. Please just use gpg.

### Use Case

Say u wanna send a sussy file to your friend on discord. You can host the file on something like transfer.sh and then send base64 encoded link with `echo link | encrypt | base64`.

## License

Do WTF u want lol i made this when i was in 10th grade to send [anime girls holding programmer books](https://github.com/cat-milk/Anime-Girls-Holding-Programming-Books) to the bois.
