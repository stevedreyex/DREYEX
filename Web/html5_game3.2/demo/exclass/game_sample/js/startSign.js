var StartSign=function(){
	this.load=function(px,py){
        this.startPic = new Framework.Sprite(define.imagePath + 'start.bmp');  //宣告圖片
        this.init_position={        //起始位置
            x:px,
            y:py-50
        }
        this.startPic.position=this.init_position;
        this.isStart=false;

	};

	this.update= function() {

	};

    this.initialize=function(){
        this.startPic.position=this.init_position;
    };

	this.mousedown= function(e) {

        this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x >= this.startPic.upperLeft.x && this.previousTouch.x <= this.startPic.upperRight.x && this.previousTouch.y >= this.startPic.upperLeft.y && this.previousTouch.y <= this.startPic.lowerLeft.y) {
            Framework.Game.goToNextLevel();
        }

    }

    this.go_out=function(){
        this.startPic.position={           //丟到畫面外
            x:1800,
            y:0
        };
    }

};