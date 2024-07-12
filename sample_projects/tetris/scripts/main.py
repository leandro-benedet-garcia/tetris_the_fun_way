from pathlib import Path
import fun_engine

class Main(fun_engine.GameObject):
    asset_path: Path

    def pre_ready():
        print("hello world")
