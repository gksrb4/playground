import click
import re
import json
import os

sub_names = ['*.smi', '*.srt']
movie_names = ['*.mp4', '*.mov', '*.wmv', '*.avi', '*.avchd', '*.flv', '*.f4v', '*.swf', '*.mkv', '*.webm']

is_subtitle_name = False

# return [[],[],[]...]
def find_pair_files(files):
    return [[]]

def get_subtitile_file(pair):
    pass

def rename_file(pair):
    pass


@click.command()
@click.option('--dir', default='.', help='directory to changing name')
@click.option('--name', help='target name')
def main(dir, name):
    global is_subtitle_name
    if name == 'sub':
        is_subtitle_name = True
    files = os.walk(dir)
    # print(files)
    for f in files:
        print(f)
    pairs = find_pair_files(files)
    for p in pairs:
        print('pair: ')
        for i in range(0, len(p)):
            f = p[i]
            print(f)

if __name__ == '__main__':
    main()