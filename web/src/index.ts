class EdgeDetectionViewer {
    private canvas: HTMLCanvasElement;
    private ctx: CanvasRenderingContext2D;

    constructor() {
        this.canvas = document.getElementById('canvas') as HTMLCanvasElement;
        this.ctx = this.canvas.getContext('2d')!;
        this.initializeCanvas();
    }

    private initializeCanvas(): void {
        this.canvas.width = 640;
        this.canvas.height = 480;
        this.drawPlaceholder();
    }

    private drawPlaceholder(): void {
        this.ctx.fillStyle = '#000000';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);

        this.ctx.fillStyle = '#00FF00';
        this.ctx.font = '16px Arial';
        this.ctx.fillText('Edge Detection Viewer', 20, 40);
        this.ctx.fillText('Resolution: 640x480', 20, 80);
        this.ctx.fillText('Status: Ready', 20, 120);
    }

    public displayFrame(imageData: ImageData): void {
        this.ctx.putImageData(imageData, 0, 0);
    }
}

// Initialize viewer when DOM is ready
document.addEventListener('DOMContentLoaded', () => {
    new EdgeDetectionViewer();
});
