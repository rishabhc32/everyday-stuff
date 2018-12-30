const webpack = require('webpack');
const HtmlWebPackPlugin = require("html-webpack-plugin");
const ErroOverlayPlugin  = require("error-overlay-webpack-plugin")

module.exports = {
    module: {
        rules: [
            {
                test: /\.(js|jsx)$/,
                exclude: /node_modules/,
                use: {
                    loader: "babel-loader"
                }
            },
            {
                test: /\.html$/,
                use: {
                    loader: "html-loader"
                }
            }
        ]
    },
    resolve: {
        extensions: ['.js', '.json', '.jsx']
    },
    devtool: 'source-map',
    plugins: [
        new HtmlWebPackPlugin({
            template: "./src/index.html",
            filename: "./index.html"
        }),
        new webpack.HotModuleReplacementPlugin(),
        new ErroOverlayPlugin()
    ],
    devServer: {
        overlay: true,
        hot: true
    }
}