var GoalSign=function(){
	this.load=function(px,py){
        this.goalPic = new Framework.Sprite(define.imagePath + 'goal.bmp');  //宣告圖片
        this.goalPic.position={                                             //起始位置
            x:px,
            y:py
        };
        this.isClear = false;
	};

	this.update= function() {

	};

	this.mousemove=function(e){
		this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x > this.goalPic.upperLeft.x && this.previousTouch.x < this.goalPic.upperRight.x && this.previousTouch.y > this.goalPic.upperLeft.y && this.previousTouch.y < this.goalPic.lowerLeft.y) {
            this.isClear = true;
        }
        else{
        	this.isClear=false;
        }


	};

};