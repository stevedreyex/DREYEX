var MovingBotton=function(){
	this.load=function(px,py){
        this.bottonPic = new Framework.Sprite(define.imagePath + 'Mbotton.png');  //宣告圖片
        this.position={        //起始位置
            x:1470,
            y:127
        }
        this.bottonPic.position=this.position;
        this.isClicked=true;

	};

	this.update= function() {
        if(this.isClicked && this.position.x>1470){
            this.position.x=this.position.x-5;
        }
        if(!this.isClicked && this.position.x<1535){
            this.position.x=this.position.x+5;
        }

        this.bottonPic.position=this.position;
	};

	this.click= function(e) {

        this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x >= this.bottonPic.upperLeft.x && this.previousTouch.x <= this.bottonPic.upperRight.x && this.previousTouch.y >= this.bottonPic.upperLeft.y && this.previousTouch.y <= this.bottonPic.lowerLeft.y) {
            if(this.isClicked){
                this.isClicked=false;
            }
            else if(!this.isClicked){
                this.isClicked=true;
            }
        }

    }

    this.come_back=function(){
        //this.position={        //起始位置
         //   x:1470,
        //    y:127
       // }
        this.bottonPic.position=this.position;
    }

    this.go_out=function(){
        this.bottonPic.position={           //丟到畫面外
            x:1800,
            y:0
        };
    }


};