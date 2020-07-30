var MousePicMove=function(){
	this.load=function(px,py){
		//////////////以下圖形隨滑鼠游標移動/////////////////
        this.mousePic = new Framework.Sprite(define.imagePath + 'point.png');  //宣告圖片
        this.start_position={                                             //起始位置
            x:px,
            y:py
        };
        this.position=this.start_position;       //position是用來控制圖片位置的參數，其他物件若要訪問滑鼠圖片的位置都透過position
        this.isStart=false;

        //////////////以上圖形隨滑鼠游標移動/////////////////
	};

    this.initialize=function(){
        this.isStart=false;
        this.mousePic.position=this.start_position;
        this.position=this.start_position;
    };

	this.update= function() {
        //////////////以下圖形隨滑鼠游標移動/////////////////
        this.mousePic.position=this.position;
        //////////////以上圖形隨滑鼠游標移動/////////////////
	};

    this.mousedown= function(e) {        ////////////當滑鼠點到圖形讓isStart=true
        this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x > this.mousePic.upperLeft.x && this.previousTouch.x < this.mousePic.upperRight.x && this.previousTouch.y > this.mousePic.upperLeft.y && this.previousTouch.y < this.mousePic.lowerLeft.y) {
            this.isStart = true;
        }
    },

	this.mousemove= function(e) {        /////////當滑鼠點到圖形就讓圖形跟滑鼠動
        this.currentTouch = { x: e.x, y: e.y };
        if(this.isStart){
            this.position={
                x:e.x,
                y:e.y
            };
            this.mousePic.position=this.currentTouch;
        }
        
    };
};